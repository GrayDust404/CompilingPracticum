Program test1;
const
    cc=+2;
    dd=3;
    ee=-3;
var
    a,a2:integer;
    b:boolean;
    r:real;
    ar:array[0..1,2..5,7..8] of boolean;
    ar2:array[0..5] of boolean;
    i,j,k:integer;
    c1,c2:char;
    
procedure print;
const cc2=1;
var i2:integer;
begin
    for i2:=1 to 100 do
    begin
        if((i2 mod 2)=0)then
           write(i2)
        else 
        	write(0);
    end;
end;

function check(a,b:integer;var c:char):boolean;
begin
    check:=(not (-a=b) or (a<=b) or (a>=b))
        and ((a>b) or (a<b) or (a<>b));
end;

begin
	write(cc);
	write(dd);
	write(ee);
    a:=1;
    a2:=2;
    r:=0.13;
    write(a,a2,r);
    ar[1,3,7] :=true;
    for i:=0 to 1 do
    begin
        for j:=0 to 1 do
        begin
            for k:=0 to 1 do
            begin
                ar2[i+j+k]:=check(a,a2,c1);
            end;
        end;
    end;
    read(a);
    write(a);
    print;
end.
{End program}


