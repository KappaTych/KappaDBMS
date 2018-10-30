var input_vm = new Vue({
    el: '#app',
    data: {
      input: "",
      output: ""
    },
    methods: {
        send_query: function() {
            axios.post('http://httpbin.org/post', {query: this.input}).then((response) => {
              this.output = JSON.stringify(response.data);
            })
        }
    }
  });