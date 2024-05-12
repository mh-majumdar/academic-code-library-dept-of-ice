n=4;
a=input('Enter the sequence');
b=input('Enter the sequence');

x=2;
y=3;

p=x*a+y*b;
fprintf('DFT without property \n');

c=zeros(1,4);
x=0;
for l=0:n-1
    for k=0:n-1
        x=x+p(1,k+1)*exp(-sqrt(-1)*2*pi*l*k/n);
    end
    c(1,l+1)=x;
    x=0;
end
disp(c);

m=abs(c);
p=unwrap(angle(c));
c=(0:length(c)-1)*100/length(c);

subplot(2,1,1)
stem(c,m);
title('Magnitude');

subplot(2,1,2);
stem(c,p*180/pi);
title('Phase');

disp(p);

fprintf('DFT using linearty property \n');

d=zeros(1,4);
x=0;
for l=0:n-1
    for k=0:n-1
        x=x+a(1,k+1)*exp(-sqrt(-1)*2*pi*l*k/n);
    end
    d(1,l+1)=x;
    x=0;
end
disp(d);

e=zeros(1,4);
x=0;
for l=0:n-1
    for k=0:n-1
        x=x+b(1,k+1)*exp(-sqrt(-1)*2*pi*l*k/n);
    end
    e(1,l+1)=x;
    x=0;
end
disp(e);

final=x*d+y*e;

m=abs(final);
p=unwrap(angle(final));
final=(0:length(final)-1)*100/length(final);

subplot(2,1,1)
stem(final,m);
title('Magnitude');

subplot(2,1,2);
stem(final,p*180/pi);
title('Phase');

disp(p);

