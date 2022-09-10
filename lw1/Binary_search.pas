PROGRAM BinarySearch(INPUT, OUTPUT);
CONST
  Len = 10;
TYPE
  IntArray = ARRAY [1 .. Len] OF INTEGER;
VAR
  Buffer: IntArray;
  Pos: INTEGER;
  F: TEXT;
  Num: INTEGER;


BEGIN
  ASSIGN(F, "array.txt");
  FOR Pos := 1 TO Len
  DO
    BEGIN
      READ(F, Num);
      WRITE(OUTPUT, "*");
      Buffer[Pos] := Num
    END;
  CLOSE(F);
  
  FOR Pos := 1 TO Len
  DO
    WRITE(OUTPUT, Buffer[Pos]);
  WRITELN(OUTPUT, "??")
END.
