# Write your MySQL query statement below
select unique_id, name from Employees e left join EmployeeUNI e1 on e.id = e1.id;
