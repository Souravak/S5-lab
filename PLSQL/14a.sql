set serveroutput on
CREATE OR REPLACE PACKAGE e_pack AS
	PROCEDURE addEmp(e_id emplo.eid%type,
	e_name emplo.ename%type,
	e_addr emplo.eaddress%type,
	e_sal emplo.esalary%type);

	PROCEDURE delEmp(e_id emplo.eid%type);

	PROCEDURE listEmp;

	FUNCTION retSal (x in number) return number;
END e_pack;
/
