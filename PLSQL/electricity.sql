set serveroutput on
declare
	cursor ele is select * from users;
	unit float;
	unitc float;
	bil float;
	cus int;
	we varchar(20);
begin 
	cus := &cus;
	for i in ele loop
		if i.cusno = cus then
			bil := 0;
			unit := i.present - i.past;
			unitc := unit;
			if unit > 500 then
				bil := bil + 100 * 5 + 200 * 7.5 + 200 * 15;
				unit := unit -500;
				bil := bil + unit * 22.5;
			elsif unit>300 then
				bil := bil + 100 * 5 + 200 * 7.5;
				unit := unit - 300;
				bil := bil + unit * 15;
			elsif unit > 100 then 
				bil := bil + unit * 5;
				unit := unit - 100;
				bil := bil + unit * 7.5;
			else
				bil := bil * 5;
			end if;
			dbms_output.put_line('customerno : ' ||i.cusno);
			dbms_output.put_line('Name : ' || i.name);
			dbms_output.put_line('unit consumed :' ||unitc);
			dbms_output.put_line('Bill amount : ' || bil);
			select to_char (current_date,'dd-mm-yyyy') into we from dual;
			dbms_output.put_line('Date : '||we);
		end if;
	end loop;
end;
/



