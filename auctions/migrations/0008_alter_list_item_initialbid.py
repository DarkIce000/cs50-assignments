# Generated by Django 4.2.4 on 2023-11-02 13:46

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('auctions', '0007_alter_list_item_comments'),
    ]

    operations = [
        migrations.AlterField(
            model_name='list_item',
            name='initialBid',
            field=models.IntegerField(default=0),
        ),
    ]
