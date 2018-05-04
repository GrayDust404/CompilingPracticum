{This program is used to test all productions}
Program test1;
const
    cc=+2;
    dd=3;
    ee=-3;
var
    a,a2:integer;
    b:boolean;
    r:real;
    ar:array[0..1,2..3,7..8] of boolean;
    i,j,k:integer;
    c1,c2:char;
    
procedure print;
var i2:integer;
begin
    for i2:=1 to 100 do
    begin
        if(ar[1]=true)then
            write(a,'''',a2,' ',b,' ',cc,' ',r)
        else if(ar[0]=true)then
            write(a2,' ',a,' ',a2,' ',a ,' ',a2);
    end;
end;

function check(a,b:integer;var c:char):boolean;
begin
    check:=(not (-a=b) or (a<=b) or (a>=b))
        and ((a>b) or (a<b) or (a<>b));
end;

begin
    a:=1;
    a2:=2;
    r:=0.13;
    for i:=0 to 1 do
    begin
        for j:=0 to 1 do
        begin
            for k:=0 to 1 do
            begin
                ar[i+j+k]:=check(a,a2);
            end;
        end;
    end;
end.
{End program}

