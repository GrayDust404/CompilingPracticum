program bubblesort;
var ar:array[0..10]of integer;
    i:integer;
    tmp:integer;
    spacec:char;
procedure bs(l,r:integer);
var tmp,i,j:integer;
begin
    for i:=1 to r-l do
        for j:=l to (r-i) do
            if ar[j]>ar[j+1] then
            begin
                tmp:=ar[j];
                ar[j]:=ar[j+1];
                ar[j+1]:=tmp;
            end;
end;
begin
    for i:=0 to 10 do
    begin
        read(tmp);
        ar[i]:=tmp;
    end;
    bs(0,10);
    //spacec:=' ';
    for i:=0 to 10 do
    begin
        tmp:=ar[i];
        write(tmp);
    end;
end.
