# Write your MySQL query statement below
select name from SalesPerson where sales_id not in (select o1.sales_id from Orders o1, Company c1 where (o1.com_id = c1.com_id and c1.name = "RED"));