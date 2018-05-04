Program test1(aaa);
var geta:integer;
function Righttest:integer;
begin
	Righttest:=1;
end;
procedure Righttest2(a1:integer;var res:integer);
var a2:integer;
begin
	if a1=Righttest then
		a2:=Righttest+a1
	else
		a2:=Righttest-a1;
	res:=a2;
end;
begin
	Righttest2(1,geta);
	Righttest2(geta+Righttest,geta);
end.