SET SERVEROUTPUT ON
CREATE OR REPLACE PACKAGE BODY e_pack AS
	PROCEDURE addEmp(e_id emplo.eid%type,
	e_name emplo.ename%type,
	e_addr emplo.eaddress%type,
	e_sal emplo.esalary%type)
	IS
	BEGIN
		INSERT INTO emplo(eid,ename,eaddress,esalary) VALUES(e_id,e_name,e_addr,e_sal);
	END addEmp;

	PROCEDURE delEmp(e_id emplo.eid%type)
	IS
	BEGIN
		DELETE FROM emplo WHERE eid=e_id;
	END delEmp;

	PROCEDURE listEmp
	IS
	CURSOR e_emp IS SELECT ename FROM emplo;
	TYPE e_list IS TABLE OF emplo.ename%type;
	name_list e_list := e_list();
	counter integer := 0;
	BEGIN
		FOR n IN e_emp LOOP
			counter := counter+1;
			name_list.extend;
			name_list(counter) := n.ename;
			dbms_output.put_line('Employee ('||counter||') = '||name_list(counter));
		END LOOP;
	END listEmp;

	FUNCTION retSal (x in number) RETURN number
	IS
	sal number(5) := 0;
	BEGIN
		SELECT esalary INTO sal FROM emplo WHERE eid=x;
		dbms_output.put_line(sal);
		RETURN sal;
	END retSal;
END e_pack;
/
