create or replace trigger p
before
insert or update of rollno, name, mark1, mark2 or delete on student1 for each row
begin
	case
		when inserting then
			alter table student1 add aveg float;
			alter table student1 add total int;
			update student1 set aveg=:new.mark1+:new.mark2;
	end case;
end;
/
