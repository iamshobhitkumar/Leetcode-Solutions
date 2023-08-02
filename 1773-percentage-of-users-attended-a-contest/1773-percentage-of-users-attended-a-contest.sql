# Write your MySQL query statement below
select contest_id, round(count(Users.user_id)*100/(select count(*) from Users),2) as percentage
from Users, Register
where Users.user_id = Register.user_id
group by contest_id
order by percentage desc, contest_id;