# Write your MySQL query statement below
select name from (select managerId,count(*) as c from Employee group by managerId) t, Employee e
where e.id = t.managerId and t.c>=5;