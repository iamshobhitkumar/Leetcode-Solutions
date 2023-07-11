# Write your MySQL query statement below
select name, bonus from Employee left join Bonus on Employee.empId = Bonus.empId having bonus<1000 or bonus is NULL;
