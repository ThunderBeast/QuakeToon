
ffi = require "ffi"

print ffi

ffi.cdef[[
	int moonscript_echo(int x);
]]

print ffi.C.moonscript_echo(42)
	
func_a = -> print "hello world"

func_a()
    
