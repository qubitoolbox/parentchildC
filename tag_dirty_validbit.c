package cache_def;
  //These are the data structures for the cache, tag and data
  parameter int TAGMSG = 31;
  parameter int TAGLSB = 14;
  
  typedef struct packed
  {
    //allocation of the value for when the
    //the check is a valid.
    bit valid;
    //Set when the value is valid, and also when the
    //value is set to be written to memory.
    bit dirty;
    bit [TAGMSB:TAGLSB]tag;
  }cache_tag_type;
  
  //data structure for cache memory request
  typedef struct
  {
    //here we declare the inde values bits
    //bit nine trhough zero.
    bit [9:0]index;
    //this bit works along the dirty bit
    //as its set when such is also true
    bit writeEnabled;
  }cache_req_type;
  
  //128 bit cache line data
  typedef bit [127:0]cache_data_type;
  
  //Cache controller interface
  //data structures for cpu
  //CPU request, coming from the CPU to the
  //cache controller.
  
  typedef struct
  {
    //specifies the address of the cache block
    bit [31:0]addr;
    // how much information are we preparing to send
    bit [31:0]data;
    // works along the dirty bit as well
    bit readwrite;
    // set when such value is true in the cache
    bit valid;
  }cpu_req_type;
  
  //cache result from the cache controller to the CPU
  typedef struct
  {
    bit [31:0]data;
    bit ready;
  }cpu_result_type;
  
  //from data structure to the cache controller 
  typedef struct
  {
    bit [31:0]addr;
    bit [127:0]data;
    bit readwrite;
    bit valid;
  }mem_req_type;
  
  //memory controller response
  
  typedef struct
  {
    cache_data_type data;
    bit ready;
  }mem_data_type;
  
endpackage
