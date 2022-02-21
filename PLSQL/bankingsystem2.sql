set serveroutput on
DECLARE
	xaccno int;
	xminbal number(3) := 500;
	xbal number(5);
BEGIN
	xaccno := &xaccno;
	select accbal into xbal from account where accno = xaccno;
	IF (xminbal<(xbal-200))then
		update account set accbal = accbal - 200 where accno = xaccno;
		xbal := xbal-200;
		dbms_output.put_line('Current balance : '||xbal);
	ELSE 
		dbms_output.put_line('Unsuccessful');
		dbms_output.put_line('Current balance : '||xbal);
	END IF;
END;
/
