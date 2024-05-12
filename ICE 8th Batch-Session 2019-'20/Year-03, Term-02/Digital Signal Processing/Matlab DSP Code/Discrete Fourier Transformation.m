a=input('Enter the sequence');
n=input('Enter value greater than size(x)')

if n>length(a)
    for i=1:n-length(a)
        a=[a 0];
    end
end

f=[];
x=0;
for i=0:n-1
    for j=0:n-1
        x=x+a(j+1)*exp(-j*2*pi*i*j/n);
    end
    f=[f x];
    x=0;
end
disp(f);
