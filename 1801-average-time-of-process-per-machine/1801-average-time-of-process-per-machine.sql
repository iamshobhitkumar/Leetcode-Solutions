# Write your MySQL query statement below
select e.machine_id, round(avg(e.timestamp - a.timestamp),3) as processing_time
from Activity a join Activity e
on a.machine_id = e.machine_id and a.process_id = e.process_id
and a.activity_type = 'start' and e.activity_type = 'end'
group by e.machine_id;
