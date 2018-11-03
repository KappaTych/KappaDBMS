const OK = 1

var inputVm = new Vue({
  delimiters: ['[[', ']]'],
  el: '#app',
  data: {
    input: "",
    output: ""
  },
  methods: {
    sendQuery: function () {
      axios.post('http://httpbin.org/post',
        {
          name: 'test-table',
          columns: ['id', 'year'],
          code: 1,
          rows: [{ id: 1, year: 1 }]
        })
        .then((response) => {
          json = JSON.parse(response.data.data)
          table.name = json.name
          table.gridColumns = json.columns
          table.gridData = json.rows
          code = json.code
          dispatchResponse(code)
        })
    }
  }
});

function dispatchResponse(code) {
  if (code === OK)
    return
  alert("An error iccured ;-(")
}

Vue.component('kappa-table', {
  template: '#kappa-table-template',
  props: {
    data: Array,
    columns: Array,
    filterKey: String
  },
  data: function () {
    var sortOrders = {}
    this.columns.forEach(function (key) {
      sortOrders[key] = 1
    })
    return {
      name: '',
      sortKey: '',
      sortOrders: sortOrders
    }
  },
  computed: {
    filteredData: function () {
      var sortKey = this.sortKey
      var filterKey = this.filterKey && this.filterKey.toLowerCase()
      var order = this.sortOrders[sortKey] || 1
      var data = this.data
      if (filterKey) {
        data = data.filter(function (row) {
          return Object.keys(row).some(function (key) {
            return String(row[key]).toLowerCase().indexOf(filterKey) > -1
          })
        })
      }
      if (sortKey) {
        data = data.slice().sort(function (a, b) {
          a = a[sortKey]
          b = b[sortKey]
          return (a === b ? 0 : a > b ? 1 : -1) * order
        })
      }
      return data
    }
  },
  filters: {
    capitalize: function (str) {
      return str.charAt(0).toUpperCase() + str.slice(1)
    }
  },
  methods: {
    sortBy: function (key) {
      this.sortKey = key
      this.sortOrders[key] = this.sortOrders[key] * -1
    }
  }
})

var table = new Vue({
  delimiters: ['[[', ']]'],
  el: '#table',
  data: {
    name: '',
    searchQuery: '',
    gridColumns: [],
    gridData: []
  }
})