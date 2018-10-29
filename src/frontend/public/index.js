var input_vm = new Vue({
    el: '#input_area',
    data: {
      input: "",
    },
    methods: {
        send_query: function() {
            //$.post('/remote-url', {xml: yourXMLString });
            output_vm.output = this.input
        }
    }
  });

var output_string = ""

var output_vm = new Vue({
    el: '#output_area',
    data: {
      output: output_string,
    },
  });