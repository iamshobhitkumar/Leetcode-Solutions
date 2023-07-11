# Write your MySQL query statement below
select s.teacher_id, count(s.teacher_id) as cnt from (select teacher_id
from Teacher
group by teacher_id,subject_id) s
group by s.teacher_id;
