file bomb
break main
run solution.txt
print &row0
x/16bx &row0
print *(long*)((char*)&row0 + 8)
x/16bx *(long*)((char*)&row0 + 8)
print *(long*)(*(long*)((char*)&row0 + 8) + 8)
x/16bx *(long*)(*(long*)((char*)&row0 + 8) + 8)
print *(long*)(*(long*)(*(long*)((char*)&row0 + 8) + 8) + 8)
x/16bx *(long*)(*(long*)(*(long*)((char*)&row0 + 8) + 8) + 8)
print *(long*)(*(long*)(*(long*)(*(long*)((char*)&row0 + 8) + 8) + 8) + 8)
x/16bx *(long*)(*(long*)(*(long*)(*(long*)((char*)&row0 + 8) + 8) + 8) + 8)
