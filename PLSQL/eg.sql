set serveroutput on
create or replace function ab(x in number) return varchar is msg varchar(20);
begin
	if(x>450)then
		msg:='Platinum';
	else
		msg:='asd';
	end if;
	return msg;
end;
/
--@/home/csdb05/Ajay/PLSQL/eg.sql
