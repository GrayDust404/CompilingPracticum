program testRight;
var i1,i2:integer;
 r1,r2:real;
 c1,c2:char;
 b1,b2:boolean;
function func(var f1,f2:integer;f3,f4,f5:real):integer;
begin
 f1:=f2;
 if(f3+f4>f5)then
  func:=f1;
end;
begin
	c1:=c2;
	i1:=i2+func(i1,i2,r1,r2,r1+r2);
	i2:=func(1,2,3.0,4.0,5.0);
end.