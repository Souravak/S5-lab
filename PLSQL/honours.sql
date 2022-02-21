set serveroutput on
declare
	cursor std is select * from students where grade1+grade2>12 order by rollno;
	great float;
begin
	for i in std loop
		if (i.grade1>i.grade2) then
			great := i.grade1;
		else
			great := i.grade2;
		end if;
		dbms_output.put_line(i.name||' '||great);
	end loop;
end;
/
