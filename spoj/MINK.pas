const
  MaxN    = 17000;
 
type
  IndN     = 1..MaxN;
  Arr1LInt = array[IndN] of LongInt;
 
var
  tests, n, k: LongInt;
  A, S, P    : Arr1LInt;
(*------------------------------*)
  procedure ReadIn;
  var i: LongInt;
  begin
    read(n, k);
    for i := 1 to n do read(A[i]);
  end;
(*------------------------------*)
  procedure Execute;
  var i, bot, top: LongInt;
  begin
    bot := 1; top := 0;
    for i := 1 to k - 1 do
    begin
      while (top >= bot) and (A[i] < S[top]) do Dec(top);
      Inc(top); S[top] := A[i]; P[top] := i;
    end;
 
    for i := 1 to n - k + 1 do
    begin
      while (top >= bot) and (A[i + k - 1] < S[top]) do Dec(top);
      Inc(top); S[top] := A[i + k - 1]; P[top] := i + k - 1;
      write(S[bot], ' ');
      while (top >= bot) and (P[bot] <= i) do Inc(bot);
    end;
 
    WriteLn;
  end;
(*------------------------------*)
begin
  read(tests);
  while tests > 0 do
  begin
   ReadIn;
   Execute;
   Dec(tests);
  end;
end.
