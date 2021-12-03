/*Function to free memory allocated using malloc*/
void free_n(void *ptr)
{
        /*header points to the beginning of the metadata of malloc allocation*/
        size_t *header = (char *)ptr - SIZE_T_SIZE;
        *header = *header & ~1L;//set the status bit of the metadata to 0
        return;
}
