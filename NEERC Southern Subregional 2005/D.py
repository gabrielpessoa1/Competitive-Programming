n = int(input())
 
v = []
for i in range (n):
	x = int(input())
	v.append(x)
list.sort(v)
ok = False
for i in range(n-2):
	if (v[i]+v[i+1] > v[i+2]) :
		print("{} {} {}".format(v[i], v[i+1], v[i+2]))
		ok = True
		break
if (not ok) :
	print("0 0 0")