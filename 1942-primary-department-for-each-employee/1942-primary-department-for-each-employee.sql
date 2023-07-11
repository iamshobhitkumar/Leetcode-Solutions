# Write your MySQL query statement below
select e.employee_id, e.department_id from Employee e, 
(select employee_id, count(*) as cnt
from Employee
group by employee_id) s
where s.employee_id = e.employee_id and (s.cnt =1 or e.primary_flag = 'Y');