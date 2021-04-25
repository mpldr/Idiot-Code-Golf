n=int(input())
print([i for i
in range(n,2*n
) if all(not i
%j==0 for j in
range(2, i))])
