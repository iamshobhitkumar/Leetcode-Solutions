# Write your MySQL query statement below
select product_name, s.year, price from Sales s, Product p where s.product_id  = p.product_id;
