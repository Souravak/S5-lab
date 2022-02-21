accept x number prompt 'Enter employee ID of whose salary you want to display: ' 
DECLARE
	code emplo.eid%type;
	salary emplo.esalary%type;
BEGIN
	code := &x;
	e_pack.addEmp(4,'RAJU','GOA',4000);
	e_pack.addEmp(6,'RAMU','GOA',50000);
    e_pack.addEmp(7,'REMA','GOA',5600);
    e_pack.addEmp(8,'RIYA','GOA',4000);
    e_pack.addEmp(9,'RIDHU','GOA',32000);
	e_pack.listEmp;
	e_pack.delEmp(5);
	e_pack.listEmp;
	salary := e_pack.retSal(code);
END;
/