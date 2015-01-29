const
        fi='';
        fo='';
var     a,b,s:ansistring;
        fa,fb:array[1..2000]of boolean;
        f:array[0..2000,0..2000]of longint;
        back:array[0..2000]of longint;
        i,j,res:longint;
begin
        assign(input,fi);       assign(output,fo);
        reset(input);           rewrite(output);
        readln(s);               readln(a);              readln(b);
        for i:=1 to length(s)-length(a)+1 do fa[i]:=true;
        for i:=length(s) downto length(b) do fb[i]:=true;
        fillchar(fb,sizeof(fb),true);

        for i:=1 to length(s) do
                for j:=1 to length(a) do
                if s[i+j-1]<>a[j] then
                begin
                        fa[i]:=false;
                        break;
                end;
        for i:=length(s) downto 1 do
                for j:=1 to length(b) do
                if s[i+1-j]<>b[length(b)-j+1] then
                begin
                        fb[i]:=false;
                        break;
                end;

        for i:=1 to length(s) do
                for j:=1 to i-1 do
                begin
                        if s[i]=s[j] then f[i,j]:=f[i-1,j-1]+1;
                        if back[i]<f[i,j] then back[i]:=f[i,j];
                end;
        for i:=1 to length(s) do
                for j:=i to length(s)do
                begin
                        if(fa[i])and(fb[j])and(back[j]<j-i+1)
                        and(j-i+1>=length(b))and(j-i+1>=length(a))then
                                inc(res);
                end;
        writeln(res);
end.
