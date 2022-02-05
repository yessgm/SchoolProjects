# Usage

Clone repository:
```bash
git clone https://git.txstate.edu/y-g159/TeamProject.git
cd TeamProject
```

Install packages:
```bash
# Using pip
pip install -r requirements.txt

# Using Conda
conda create --name <env_name> --file requirements.txt
```

Apply changes to remote repository:
```bash
git stash
git pull
git stash apply
git add <files>
git commit -m "<commit message>"
git push origin
```

# Documentation

Historically, student eligibility for free or reduced-price lunch (FRPL) was determined through individual students submitting school meals application forms within school districts. In 1986, the USDA introduced a direct certification option to reduce participation barriers in the school meal program. Under direct certification, any child belonging to a household that participates in Supplemental Nutrition Assistance Program (SNAP), Temporary Assistance for Needy Families (TANF), Food Distribution Program on Indian Reservations (FDPIR), or (in some states) Medicaid—as well as children who are migrant, homeless, in foster care, or in Head Start—are categorically eligible to receive free meals at school.

The NSLP data included in CCD releases include school-level FRPL and direct certification eligibility counts for all public schools with students enrolled. These point-in-time counts are taken on or around October 1 of each school year and reported by the states based on the following guidance:

- FRPL-Eligible Students
  - Free lunch students: those eligible to participate in the Free Lunch Program (i.e., those with family incomes below 130 percent of the poverty level or who are directly certified)
  - Reduced-price lunch students: those eligible to participate in the Reduced-Price Lunch Program (i.e., those with family incomes between 130 and 185 percent of the poverty level)
  - Free and reduced-price lunch student: the total of free lunch students and reduced-price lunch students

## Features

Documentation link found [here](https://nces.ed.gov/ccd/elsi/glossary.aspx?app=tableGenerator&term=11020,9558,13403,13392,15188,7861,7196,7258,2275,2265,5446,6037,6348,7133,7570,6450,5145&level=PublicSchool&groupby=0)

School Name
> This is the name of the public school.

State Name
>This is the name of the state.

State Abbr
> This is the USPS abbreviation for the state.

School ID - NCES Assigned
> This is the five digit number used by NCES to identify a school. Together with the NCES Agency ID, it uniquely identifies a school.

Agency ID - NCES Assigned
> This is the seven digit code used by NCES to uniquely identify a school district. The first two digits are the ANSI/FIPS state code.

School-wide Title I
> A program in which all the pupils in a school are designated under appropriate state and federal regulations as being eligible for participation in programs authorized by Title I of Public Law 103-382.

Total Students, All Grades (Excludes AE)
> This is the total number of students as reported by each school. A student is an individual for whom instruction is provided in an elementary or secondary educational program under the jurisdiction of a school, school system, or other educational institution. This count excludes adult education students, which is the number of students enrolled in adult education courses provided by the public elementary/secondary school system.

Free and Reduced Lunch Students
> This is the total of Free Lunch Eligible students and Reduced-price Lunch Eligible students. The total is only available if both details were reported.

Male Students
> Total number of male students in all grades.

Female Students
> Total number of female students in all grades.

American Indian/Alaska Native Students
> This is the number of students having origins in any of the original peoples of North America, and who maintain cultural identification through tribal affiliation or community recognition as reported by each school.

Asian or Asian/Pacific Islander Students
> This is the number of students having origins in any of the original peoples of the Far East, Southeast Asia, the Indian subcontinent, or the Pacific Islands as reported by each school.
>
> NOTE: Prior to 2008-09, this count includes Asian, Hawaiian Native, and Other Pacific Islander students. Starting in 2008-09, this count only includes Asian students; Hawaiian Native and Other Pacific Islander students are shown in a separate student count.

Black or African American Students
> This is the number of students having origins in any of the black racial groups of Africa as reported by each school.

Hispanic Students
> This is the number of students having Mexican, Puerto Rican, Cuban, Central or South American, or other Spanish culture or origin, regardless of race as reported by each school.

White Students
> This is the number of students having origins in any of the original peoples of Europe, North Africa, or the Middle East, as reported by each school.

Full-Time Equivalent (FTE) Teachers
> This is the number of Full Time Equivalent teachers as reported by each school. A teacher is defined as a professional school staff member who instructs students and maintains daily student attendance records. This count totaled to the district level will not necessarily agree with the district count of teachers, as not all teachers are assigned to a specific school.

Pupil/Teacher Ratio
> This is the calculated Pupil Teacher Ratio: The total reported students divided by the FTE classroom teachers.