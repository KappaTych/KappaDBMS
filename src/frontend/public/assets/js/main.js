const OK = 1;

const app = new Vue({
  delimiters: ['[[', ']]'],
  data: {
    input: "",
    output: "",
    table: {
      name: '',
      query: '',
      columns: [],
      data: [],
    },
  },
  methods: {
    sendQuery: function () {
      axios.post('http://localhost:8000/query', this.input) //http://httpbin.org/post
        .then((response) => {
          // data = JSON.parse(response.data.data);
          this.table.name = 'test-table';
          this.table.columns = ['id', 'year'];
          this.table.data = [{ id: 1, year: 2018 }];
          // this.table.name = data.name;
          // this.table.columns = data.columns;
          // this.table.data = data.rows;
          // handleResponse(data.code);
          this.output = response.data;
        })
    }
  }
}).$mount('#app')
// {
//   name: 'test-table',
//   columns: ['id', 'year'],
//   code: 1,
//   rows: [{ id: 1, year: 1 }]
// }


function handleResponse(code) {
  if (code === OK)
    return false;
  alert("An error iccured -(");
  return true;
}
