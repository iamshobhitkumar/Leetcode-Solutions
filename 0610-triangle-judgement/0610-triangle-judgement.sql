# Write your MySQL query statement below
select x,y,z, case when x+y<=z OR x+z<=y OR y+z<=x then 'No' else 'Yes' end as 'triangle' from Triangle;