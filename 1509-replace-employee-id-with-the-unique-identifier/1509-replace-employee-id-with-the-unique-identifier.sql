# Write your MySQL query statement below
select e1.unique_id, e2.name from Employees e2 left join EmployeeUNI e1 on (e1.id = e2.id);