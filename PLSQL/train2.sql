set serveroutput on
accept x char prompt '1.Reserve  2.Cancel : ';
declare
	choice varchar(2);
	tseat number(3);
	trainno number(5);
	no number(4);
begin
	choice := &x;
	trainno := &trainno;
	no := &no;
	select seats into tseat from train where tno = trainno;
	case choice
		when '1' then 
			tseat := tseat - no;
			update train set seats = tseat where tno = trainno;
		when '2' then
			tseat := tseat + no;
			update train set seats = tseat where tno = trainno;
	end case;
end;
/
