set serveroutput on
DECLARE
	msg varchar(20);
	average number(5);
	no number(5);
	today date;
	day varchar(10);
BEGIN
	select avg(mark) into average from student;
	dbms_output.put_line('Average marks : '||average);
	if (average<40) then
		dbms_output.put_line('Need improvement');
	end if;
	select to_char(current_date, 'dd-mm-yyyy') into today from student group by rollno having rollno = 1;
	dbms_output.put_line('Date : '||today);
	select to_char(current_date, 'Day') into day from student group by rollno having rollno = 1;
	dbms_output.put_line('Day : '||day);
END;
/
