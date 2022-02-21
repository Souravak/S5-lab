set serveroutput on
create sequence train_se;
create or replace trigger train_ins
before 
insert on train for each row
begin
	select train_seqe.nextval into :new.tno from dual;
end;
/
