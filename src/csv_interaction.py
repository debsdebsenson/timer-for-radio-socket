import csv

def create_csv_file(filename, fields):

    # writing to csv file 
    with open(filename, 'w') as csvfile:

        # creating a csv writer object 
        csvwriter = csv.writer(csvfile)

        # writing the fields 
        csvwriter.writerow(fields)


def append_to_existing_csv(filename, rows):

    # writing to csv file 
    with open(filename, 'a') as csvfile:

        # creating a csv writer object 
        csvwriter = csv.writer(csvfile)

        # writing the data rows
        csvwriter.writerows(rows)
