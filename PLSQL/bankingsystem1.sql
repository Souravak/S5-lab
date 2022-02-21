set serveroutput on
accept x char prompt '1.Debit   2.Credit   3.Check balance  :  '
DECLARE
	choice varchar(1);
	amount number(5);
	msg varchar(20);
	no number(5);
BEGIN
	no := &no;
	amount := &amount;
	choice := &x;
	case
		when choice = '1' then
			update account set accbal = accbal - amount where accno = no;
			dbms_output.put_line('Debited');
		when choice = '2' then
			update account set accbal = accbal + amount where accno = no;
			dbms_output.put_line('Credited');
		when choice = '3' then
			select accbal into amount from account where accno = no;
			dbms_output.put_line('Balance '||amount);
	END CASE;
END;
/
