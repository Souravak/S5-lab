accept x number prompt 'Enter employee ID of whose salary you want to display: ' 
DECLARE
	code emplo.eid%type;
	salary emplo.esalary%type;
BEGIN
	code := &x;
	e_pack.addEmp(4,'ABC','XYZ',4000);
	e_pack.addEmp(5,'BC','YZ',5000);
	e_pack.listEmp;
	e_pack.delEmp(5);
	e_pack.listEmp;
	salary := e_pack.retSal(code);
END;
/
