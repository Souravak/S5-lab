set serveroutput on
create or replace trigger t 
before
insert or update of roll_no, name, grade_s1, grade_s2 or delete on students1 for each row
begin
	case
		when inserting then
			dbms_output.put_line('Trigger message : inserting ' ||:new.name);
		when updating('roll_no') then
			dbms_output.put_line('Trigger message : updating ' ||:new.name||':old roll_no-'||:old.roll_no||' to new roll_no-'||:new.roll_no);
		when updating('name') then
			dbms_output.put_line('Trigger message : updating ' ||:new.name||':old name-'||:old.name||' to new name-'||:new.name);
		when updating('grade_s1') then
			dbms_output.put_line('Trigger message : updating ' ||:new.name||':old grade_s1-'||:old.grade_s1||' to new grade_s1-'||:new.grade_s1);
		when updating('grade_s2') then
			dbms_output.put_line('Trigger message : updating ' ||:new.name||':old grade_s2-'||:old.grade_s2||' to new grade_s2-'||:new.grade_s2);
		when deleting then
			dbms_output.put_line('Trigger message : deleting ' ||:old.name);
	end case;
end;
/
