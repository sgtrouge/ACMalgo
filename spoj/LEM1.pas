Uses Math;
Const
        Fi='';
        Fo='';
        Eps=0.000000000001;
Var
        N:longint;
        A:array[1..10001]of real;
//-------------------------------CHECK-----------------------------------
Function Check(mid:real):real;
Var
        Tmp,x,y,z:real;
        I:longint;
Begin
        Check:=0;
        For i:=1 to n do
        Begin
                X:=a[i]+a[i+1];
                Y:=mid+a[i];
                Z:=mid+a[i+1];
                Tmp:=(sqr(y)+sqr(z)-sqr(x))/(2*y*z);
                Check:=check+arccos(tmp);
        End;
End;
//-------------------------------INIT------------------------------------
Procedure Init;
Var
        I:longint;
Begin
        Assign(input,fi);
        Assign(output,fo);
        Reset(input);
        Rewrite(output);
        Readln(n);
        For i:=1 to n do
                Read(a[i]);
        A[n+1]:=a[1];
End;
//-------------------------------SOLVE-----------------------------------
Procedure Solve;
Var
        L,r,mid,tmp:real;
Begin
        L:=0;   R:=maxlongint;
        Repeat
                Mid:=(l+r)/2;
                Tmp:=check(mid);
                If abs(Tmp-2*pi)<eps then
                Begin
                        Writeln(mid:0:3);
                        Halt;
                End;
                If tmp>2*pi then
                        L:=mid
                Else
                        R:=mid;
        Until false;
End;
//-------------------------------MAIN------------------------------------
Begin
        INIT;
        SOLVE;
End.


