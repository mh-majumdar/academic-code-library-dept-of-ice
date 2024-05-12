%array input

n=input('Enter the size of the array:');
a=zeros(1,n);
for i=1:n
    a(i)=input('');
end;

disp('The array is:');
disp(a);