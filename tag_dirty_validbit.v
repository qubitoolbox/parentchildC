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
    
  
  }
