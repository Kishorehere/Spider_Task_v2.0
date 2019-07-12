def ksp(W,wt,val,n):
    if(n==0 or W==0):
      f[0]=0
      return 0
    if(wt[n-1]>W):
        f[n-1]=0
        return ksp(W,wt,val,n-1)
    else:
        f[n-1]=1
        return max(val[n-1]+ksp(W-wt[n-1],wt,val,n-1),ksp(W,wt,val,n-1))

    
n=int(input('enter no. of elements'))
val=list(map(int,input('enter the values of the elements in order: ').split()))
wt=list(map(int,input('enter the weights of the elements in order: ').split()))
W=int(input('enter max weight: ' ))
f=list(map(int,input('enter n-zeroes where n is the no. of items: ').split()))
print('max value of elements=', ksp(W,wt,val,n))
print('fraction',"\n")
print(*f, sep=" , ")

    
