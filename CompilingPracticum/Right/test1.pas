{Program example;
var x,y:integer;
function gcd(a,b:integer):integer;
begin
 if b=0 then gcd:=a
 else gcd:=gcd(b,a mod b);
end;
begin
 read(x,y);
 write(gcd(x,y));
end.}
Program example;
const c1=0.0;
var x,y,tmp:integer;
function gcd(a,b:integer):integer;
begin
	if b=0 then gcd:=a
	else gcd:=gcd(b,a mod b);
end;
begin
	read(x,y);
	tmp:=gcd(x,y);
	write(tmp);
end.