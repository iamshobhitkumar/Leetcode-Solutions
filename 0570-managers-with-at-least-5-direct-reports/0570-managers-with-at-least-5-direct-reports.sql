# Write your MySQL query statement below
select name from Employee e, (select managerId from Employee 
group by managerId having count(*)>=5) t
where e.id = t.managerId;