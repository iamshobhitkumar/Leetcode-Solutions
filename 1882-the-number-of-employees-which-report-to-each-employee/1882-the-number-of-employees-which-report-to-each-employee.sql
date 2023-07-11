# Write your MySQL query statement below
select s.reports_to as employee_id, name, reports_count, average_age from Employees e, (select reports_to, count(*)  as reports_count, round(avg(age)) as average_age
from Employees
group by reports_to) s
where s.reports_to = e.employee_id
order by employee_id;