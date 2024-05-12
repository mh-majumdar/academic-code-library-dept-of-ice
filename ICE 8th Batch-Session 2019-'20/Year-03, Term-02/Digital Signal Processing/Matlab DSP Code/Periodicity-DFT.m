n=4;
a=input('Enter the sequence');

f=zeros(1,4);
x=0;
for l=0:n-1
    for k=0:n-1
        x=x+a(1,k+1)*exp(-sqrt(-1)*2*pi*l*k/n);
    end
    f(1,l+1)=x;
    x=0;
end
disp(f);

m=abs(f);
p=unwrap(angle(f));
f=(0:length(f)-1)*100/length(f);

subplot(2,1,1)
stem(f,m);
title('Magnitude');

subplot(2,1,2);
stem(f,p*180/pi);
title('Phase');
disp(p);

N=1;
g=zeros(1,4);
x=0;
for l=0:n-1
    for k=0:n-1
        x=x+a(mod(n + N, N)+1)*exp(-sqrt(-1)*2*pi*l*k/n);
    end
    g(1,l+1)=x;
    x=0;
end
disp(g);

m=abs(g);
p=unwrap(angle(g));
g=(0:length(g)-1)*100/length(g);

subplot(2,1,1)
stem(g,m);
title('Magnitude');

subplot(2,1,2);
stem(g,p*180/pi);
title('Phase');
disp(p);

